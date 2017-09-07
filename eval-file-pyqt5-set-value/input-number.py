import sys

class App():

    def __init__(self):
        from PyQt5.QtWidgets import QInputDialog
        num,ok = QInputDialog.getInt(None, "decrement "+ str(y) +" by ", "enter a number")
        if ok:
            set_the_answer(y - num)

def test() :
    print(y)

if __name__ == '__main__':
    from PyQt5.QtWidgets import QApplication
    # app = QApplication(sys.argv)
    print(y)
    test()
    app = QApplication(['myname'])
    ex = App()
