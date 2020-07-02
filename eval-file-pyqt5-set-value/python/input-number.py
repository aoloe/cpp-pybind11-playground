def get_the_value(outer_locals):
    from PyQt5.QtWidgets import QInputDialog
    # locals().update(outer_locals) # a way to make the locals difference explicit
    num, ok = QInputDialog.getInt(None, 'The number to be set', 'enter a number')
    if ok:
        outer_locals['set_the_answer'](num)
        # locals()['set_the_answer'](num)
        # set_the_answer(num) # this cannot work (see README)

if __name__ == '__main__':
    from PyQt5.QtWidgets import QApplication
    app = QApplication(['myname'])
    get_the_value(locals())
