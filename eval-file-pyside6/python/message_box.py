import sys
# sys.path.append('/home/ale/src/cpp-pybind11-playground/venv/lib/python3.11/site-packages/')
from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QMessageBox

class App():

    def __init__(self):
        buttonReply = QMessageBox.question(None, 'PyQt5 message', "Do you like PyQt5?", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if buttonReply == QMessageBox.Yes:
            print('Yes clicked.')
        else:
            print('No clicked.')

if __name__ == '__main__':
    # app = QApplication(sys.argv)
    app = QApplication([])
    ex = App()
