import sys

class App():

    def __init__(self):
        from PyQt5.QtWidgets import QInputDialog
        num,ok = QInputDialog.getInt(None, "integer input dualog", "enter a number")
        if ok:
            pass 

if __name__ == '__main__':
    from PyQt5.QtWidgets import QApplication
    # app = QApplication(sys.argv)
    app = QApplication(['myname'])
    ex = App()
