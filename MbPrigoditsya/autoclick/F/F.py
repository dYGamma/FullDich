import tkinter as tk
import pyautogui
import time
import threading
from tkinter import messagebox
from pynput.keyboard import Controller, Key

class AutoPressKeyApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Auto Press Key")
        self.geometry("200x200")
        self.attributes('-topmost', True)  # Окно всегда поверх других
        self.key = tk.StringVar()
        self.interval = tk.DoubleVar()
        self.duration = tk.DoubleVar()
        self.running = False
        self.keyboard = Controller()
        self.create_widgets()

    def create_widgets(self):
        tk.Label(self, text="Key:").pack()
        tk.Entry(self, textvariable=self.key).pack()
        tk.Label(self, text="Interval (sec):").pack()
        tk.Entry(self, textvariable=self.interval).pack()
        tk.Label(self, text="Duration (sec):").pack()
        tk.Entry(self, textvariable=self.duration).pack()
        tk.Button(self, text="Start", command=self.start).pack(pady=5)
        tk.Button(self, text="Stop", command=self.stop).pack(pady=5)

    def start(self):
        if not self.running:
            self.running = True
            self.thread = threading.Thread(target=self.press_key)
            self.thread.start()

    def stop(self):
        self.running = False
        if hasattr(self, 'thread'):
            self.thread.join()

    def press_key(self):
        key = self.key.get()
        interval = self.interval.get()
        duration = self.duration.get()
        end_time = time.time() + duration

        try:
            interval = float(interval)
            duration = float(duration)
            if interval <= 0 or duration <= 0:
                raise ValueError
        except ValueError:
            self.running = False
            messagebox.showerror("Ошибка", "Интервал и длительность должны быть положительными числами.")
            return

        time.sleep(2)  # Задержка перед началом нажатия клавиш

        while self.running and time.time() < end_time:
            self.keyboard.press(key)
            self.keyboard.release(key)
            time.sleep(interval)
        self.running = False

if __name__ == "__main__":
    app = AutoPressKeyApp()
    app.mainloop()
