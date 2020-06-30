def get_the_value(locals_):
    from PyQt5.QtWidgets import QInputDialog
    num, ok = QInputDialog.getInt(None, 'The number to be set', 'enter a number')
    if ok:
        locals['set_the_answer'](num)

if __name__ == '__main__':
    from PyQt5.QtWidgets import QApplication
    app = QApplication(['myname'])
    get_the_value(locals())
