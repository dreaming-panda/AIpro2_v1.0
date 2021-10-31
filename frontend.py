# -*- coding: utf-8 -*-
import sys
from PyQt5.QtWidgets import QMainWindow, QTextEdit,QAction, QFileDialog, QApplication, QPushButton, QWidget, QGridLayout
from PyQt5.QtGui import QIcon
import os

class MainUi(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.setFixedSize(960, 700)
        self.main_widget = QWidget()  # 创建窗口主部件
        self.main_layout = QGridLayout()  # 创建主部件的网格布局
        self.main_widget.setLayout(self.main_layout)  # 设置窗口主部件布局为网格布局

        self.left_widget = QWidget()  # 创建左侧部件
        self.left_widget.setObjectName('left_widget')
        self.left_layout = QGridLayout()  # 创建左侧部件的网格布局
        self.left_widget.setLayout(self.left_layout)  # 设置左侧部件布局为网格布局

        self.right_widget = QWidget()  # 创建右侧部件
        self.right_widget.setObjectName('right_widget')
        self.right_layout = QGridLayout()  # 创建右侧部件的网格布局
        self.right_widget.setLayout(self.right_layout)  # 设置右侧部件布局为网格布局

        self.main_layout.addWidget(self.left_widget, 0, 0, 12, 2)
        self.main_layout.addWidget(self.right_widget, 0, 2, 12, 10)
        self.setCentralWidget(self.main_widget)  # 设置窗口主部件

        self.button1 = QPushButton(QIcon(''), '显示结果1')  # 创建按钮
        self.left_layout.addWidget(self.button1, 3, 0, 3, 4)
        self.textEdit = QTextEdit()  # 创建文本框用于显示
        self.right_layout.addWidget(self.textEdit, 0, 0, 4, 4)
        self.button1.clicked.connect(self.showDialog1)

        self.button2 = QPushButton(QIcon(''),"保存牌面")
        self.left_layout.addWidget(self.button2,3,0,2,4)   
        self.button2.clicked.connect(self.save_file)

        self.button3 = QPushButton(QIcon(''),"随机模式")
        self.left_layout.addWidget(self.button3,3,0,1,4)   
        self.button3.clicked.connect(self.randommode)

        self.button4 = QPushButton(QIcon(''), '显示结果2')  # 创建按钮
        self.left_layout.addWidget(self.button4, 3, 0, 4, 4)
        self.button4.clicked.connect(self.showDialog2)

        self.button5 = QPushButton(QIcon(''), '运行指定的牌面')  # 创建按钮
        self.left_layout.addWidget(self.button5, 3, 0, 5, 4)
        self.button5.clicked.connect(self.runs)      
    #定义打开文件夹目录的函数
    def showDialog1(self):
            f = open("info1.txt", 'r')
            with f:
                data = f.read()
                self.textEdit.setText(data)
    def showDialog2(self):
            f = open("info2.txt", 'r')
            with f:
                data = f.read()
                self.textEdit.setText(data)
    def save_file(self):
        txt = self.textEdit.toPlainText()
        f = open("info.txt",'w')
        f.write(txt)
    def randommode(self):
        txt = self.textEdit.toPlainText()
        cmd1 = '.\poker_backend '
        cmd2 = '.\poker_simple '
        os.system(cmd1 + txt)
        os.system(cmd2 + txt)
    def runs(self):
        cmd1 = '.\poker_backend -1'
        cmd2 = '.\poker_simple -1'
        os.system(cmd1)
        os.system(cmd2)
def main():
    app = QApplication(sys.argv)
    gui = MainUi()
    gui.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
