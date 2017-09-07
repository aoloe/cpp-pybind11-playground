import sys
from PyQt5.QtWidgets import QApplication, QInputDialog

class App():

    def __init__(self):
        num,ok = QInputDialog.getInt(None, "integer input dualog", "enter a number")
        if ok:
            pass 

if __name__ == '__main__':
    # app = QApplication(sys.argv)
    app = QApplication([])
    ex = App()
