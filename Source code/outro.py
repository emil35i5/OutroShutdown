#setup
#-------------------------------------------------------------------
from ctypes import *
from tkinter import *
import os
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "hide"
#print("\n" * 100)
from pygame import mixer
import sys
import time
from win32gui import *
from win32api import *
from win32con import *
import win32gui
import win32con

ok = windll.user32.BlockInput(True)

def resource_path(relative_path):
    try:
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.dirname(os.path.abspath(__file__))
    return os.path.join(base_path, relative_path)

def ScreenOFF():
    """
    Function to turn off the screen.
    """
    return win32gui.SendMessage(win32con.HWND_BROADCAST,
                            win32con.WM_SYSCOMMAND, win32con.SC_MONITORPOWER, 2)

def ScreenON():
    """
    Function to turn on the screen.
    """
    return win32gui.SendMessage(win32con.HWND_BROADCAST,
                            win32con.WM_SYSCOMMAND, win32con.SC_MONITORPOWER, -1)

print("\n");
print("  / __ \\      | |           / ____| |         | |    | |\n"
    " | |  | |_   _| |_ _ __ ___| (___ | |__  _   _| |_ __| | _____      ___ __\n"
    " | |  | | | | | __| '__/ _ \\\\___ \\| '_ \\| | | | __/ _` |/ _ \\ \\ /\\ / / '_ \\\n"
    " | |__| | |_| | |_| | | (_) |___) | | | | |_| | || (_| | (_) \\ V  V /| | | |\n"
    "  \\____/ \\__,_|\\__|_|  \\___/_____/|_| |_|\\__,_|\\__\\__,_|\\___/ \\_/\\_/ |_| |_|\n"
    "\n");
print("Turn off your computer with music\n");
print("\n");
print("Thanks to karl6986 on GitHub for the original project: Awesome-shutdown\n");
print("Music by TheFatRat - Xenogenesis (Outro Song)\n");
print("emil.ystrom.dk\n");

time.sleep(0.1)

#-------------------------------------------------------------------

mixer.init()
mp3_path = resource_path("song.mp3")
mixer.music.load(mp3_path)
mixer.music.play()
time.sleep(57.9)
mixer.music.pause()
ScreenOFF()
mixer.music.unpause()
time.sleep(7)
mixer.music.fadeout(7777)
time.sleep(10)
os.system("shutdown -s -t 0")