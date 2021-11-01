import os

cmd1 = "pip install pyqt5"
cmd2 = "pip install pyqt_tools"
cmd3 =  "pip install pyqt5_tools"
print(cmd1)
os.system(cmd1)
print(cmd2)
os.system(cmd2)
print(cmd3)
os.system(cmd3)

cmd4 = "g++ poker_backend.cpp -o poker_backend"
print(cmd4)
os.system(cmd4)

cmd5 = "g++ poker_simple.cpp -o poker_simple"
print(cmd5)
os.system(cmd5)

cmd6 = "g++ simulate/simulate.cpp -o simulate/simulate"
print(cmd6)
os.system(cmd6)
