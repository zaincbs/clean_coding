#!/usr/bin/env python

from Tkinter import *

root = Tk()

minutes = Label(root, text="Minutes:")

minutes.grid(row=0, column=5)

scale = Scale(root, from_=1, to=45, orient=HORIZONTAL, length=300)
scale.grid(row=0, column=1)

button = Button(root, text="Start Timing", command=quit)
button.grid(row=1, column=1, pady=5, sticky=E)

root.mainloop()
