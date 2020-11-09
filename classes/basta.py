class Menu:
    def __init__(self, name, items, start_time, end_time, purchased_items = [], start_time_calc = 0, end_time_calc = 0):
        self.name = name
        self.items = items
        self.start_time = start_time
        self.end_time = end_time
        self.purchased_items = purchased_items
        self.start_time_calc = start_time_calc
        self.end_time_calc = end_time_calc

    def __repr__(self):
        return "Menu: {name}\nAvailable From: {start} To: {end}".format(name=self.name.title(), start=self.start_time, end = self.end_time)

    def calculate_bill(self, purchased_items):
        self.purchased_items = purchased_items
        bill_total = 0
        for x in self.purchased_items:
            bill_total += self.items[x]
        print('From {menu} menu: ${bill}'.format(menu=self.name, bill=bill_total))
        return bill_total

    #this function was pretty fun to make. When codecademy wanted me to make the available_menus function work, I had to find a way to calculate the time against one time so I needed a function to do this. I replaced the 00:00 a.m./ 00:00 p.m. format to 00.00 and then slices the new string using a .find('.')
    def change_time(string):
        return_num = 0
        if 'a.m.' in string:
            new_string = string.replace(':','.').replace('a.m.','')

            index = 0
            base_number = ''
            if int(new_string[:new_string.find('.')]) == 12:
                return_num = int(new_string[:new_string.find('.')]) + int(new_string[new_string.find('.')+1:])/60 - 12
            else:
                return_num += int(new_string[:new_string.find('.')]) + int(new_string[new_string.find('.')+1:])/60
        elif 'p.m.' in string:
            new_string = string.replace(':','.').replace('p.m.','')

            index = 0
            base_number = ''
            if int(new_string[:new_string.find('.')]) == 12:
                return_num = int(new_string[:new_string.find('.')]) + int(new_string[new_string.find('.')+1:])/60
            else:
                return_num += 12 + int(new_string[:new_string.find('.')]) + int(new_string[new_string.find('.')+1:])/60
        return return_num

    def change_times(self, start_time, end_time):
        self.start_time_calc = Menu.change_time(self.start_time)
        self.end_time_calc = Menu.change_time(self.end_time)


brunch = Menu('brunch', {
  'pancakes': 7.50, 'waffles': 9.00, 'burger': 11.00, 'home fries': 4.50, 'coffee': 1.50, 'espresso': 3.00, 'tea': 1.00, 'mimosa': 10.50, 'orange juice': 3.50
},'11:00 a.m.','4:00 p.m.')

early_bird = Menu('early bird', {
  'salumeria plate': 8.00, 'salad and breadsticks (serves 2, no refills)': 14.00, 'pizza with quattro formaggi': 9.00, 'duck ragu': 17.50, 'mushroom ravioli (vegan)': 13.50, 'coffee': 1.50, 'espresso': 3.00,
}, '3:00 p.m.', '6:00 p.m.')

dinner = Menu('dinner', {
  'crostini with eggplant caponata': 13.00, 'ceaser salad': 16.00, 'pizza with quattro formaggi': 11.00, 'duck ragu': 19.50, 'mushroom ravioli (vegan)': 13.50, 'coffee': 2.00, 'espresso': 3.00,
}, '5:00 p.m.', '10:00 p.m.')

kids = Menu('kids', {
  'chicken nuggets': 6.50, 'fusilli with wild mushrooms': 12.00, 'apple juice': 3.00
}, '11:00 a.m.', '9:00 p.m.')

arepas_menu = Menu('take a\' arepa', {
  'arepa pabellon': 7.00, 'pernil arepa': 8.50, 'guayanes arepa': 8.00, 'jamon arepa': 7.50
}, '10:00 a.m.', '8:00 p.m.')

class Franchise:
  def __init__(self, address, menus, time = 0):
    self.address = address
    self.menus = menus
    self.time = time

  def __repr__(self):
    return 'Store found at: {address}'.format(address=self.address)

  def available_menus(self, time):
      menus_available = []
      time_calc = Menu.change_time(time)
      for x in self.menus:
          x.change_times(x.start_time, x.end_time_calc)
          if time_calc >= x.start_time_calc and time_calc <= x.end_time_calc:
              menus_available.append(x)
      if menus_available == []:
          print("Location closed at that time")
      else:
          return menus_available

flagship_store = Franchise('1232 West End Road', [brunch, early_bird, dinner, kids])

new_installment = Franchise('12 East Mulberry Street',[brunch, early_bird, dinner, kids])

arepas_place = Franchise('189 Fitzgerald Avenue', [arepas_menu])

class Business:
    def __init__(self, name, franchises):
        self.name = name
        self.franchises = franchises

business_1 = Business('Basta Fazoolin\' with my Heart', [flagship_store, new_installment])
business_2 = Business('Take \' Aerpa', [arepas_place])

for franchise in business_2.franchises:
    print(franchise)
    print(franchise.available_menus('11:00 a.m.'))
