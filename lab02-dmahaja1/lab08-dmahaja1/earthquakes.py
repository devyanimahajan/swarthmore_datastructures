"""
Name: Devyani Mahajan
Date: 08.11.21
"""

from earthquakes_lab import *
from graphics import *

def read_file(file_name):
  """
  Purpose: Loads data from a given file
  Parameters: String of file name
  Returns: list of data (with earthquake data)
  """
  data_list = []
  infile = open(file_name, 'r')
  while True:
    line = infile.readline()
    if line == "":
      break
    else:
      quake_data = line.strip().split(';')
      record = Earthquake(quake_data[0], float(quake_data[1]), quake_data[2], float(quake_data[3]), float(quake_data[4]), quake_data[5], quake_data[6])
      data_list.append(record)
  infile.close()
  return data_list

def get_choice():
  """
  Purpose: Takes a user's choice from a menu of choices
  Parameters: None
  Returns: User's choice
  """
  valid_choices = [1,2,3,4]
  print()
  print("Please select one of the following choices:")
  print("(1) Find by ID")
  print("(2) Find by location")
  print("(3) Map state")
  print("(4) Quit")
  print("")
  while True:
    user_choice = int(input("Choice? "))
    if user_choice in valid_choices:
      break
    else:
      print("Please enter a valid choice")
  return user_choice

def by_id(id, data_list):
  """
  Purpose: uses binary search to find id-specific records
  Parameters: List of earthquake data
  Returns: None
  """
  #print("In by_id")
  lo = 0
  hi = len(data_list)-1
  found = False
  while lo <= hi and not found:
    mid = (hi + lo)//2
    if data_list[mid].get_id() == id:
      search_result = data_list[mid]
      print(search_result)
      found = True
    elif lo > hi:
      print("No results were found")
      break
    else:
      if id < data_list[mid].get_id():
        hi = mid - 1
      else:
        lo = mid + 1



def by_location(loc, data_list):
  """
  Purpose: uses linear search to find location-specific records
  Parameters: List of earthquake data
  Returns: None
  """
  loc_results = []
  for i in range(len(data_list)):
    current_quake = data_list[i].get_location_full()
    if loc in current_quake:
      loc_results.append(data_list[i])
  if loc_results == []:
    print("Could not find any records matching that location.")
  else:
    for i in range(len(loc_results)):
      print(loc_results[i])


def map_state(data_list):
  """
  Purpose:
  Parameters: List of earthquake data
  Returns: None
  """
  state = input("Which state? ")
  min_mag = input("Minimum magnitude? ")
  while not is_float(min_mag):
    min_mag = input("Minimum magnitude? ")
  min_mag = float(min_mag)
  win = getStateGraphWin(state)
  if win == None:
    print("Unknown state:",state)
    return
  for i in range(len(data_list)):
    current_quake = data_list[i]
    if current_quake.get_location() == state and current_quake.get_magnitude() >= min_mag:
      point = Point(current_quake.get_longitude(), current_quake.get_latitude())
      radius = 2 ** current_quake.get_magnitude() * 0.01
      circ = Circle(point, radius)
      circ.setFill("green")
      circ.draw(win)
  win.getMouse()
  win.close()



def main():

  data_list = read_file("/usr/local/doc/earthquakes.txt")
  choice = get_choice()
  while choice != 4:
    if choice == 1:
      id = input("ID to search for? ")
      by_id(id, data_list)
    elif choice == 2:
      loc = input("Location? ")
      by_location(loc, data_list)
    elif choice == 3:
      map_state(data_list)
    choice = get_choice()

  print("Successfully quit")


main()
