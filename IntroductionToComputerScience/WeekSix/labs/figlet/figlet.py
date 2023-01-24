from pyfiglet import Figlet
from sys import argv
import random


def main():
    arg = get_arguments()
    usr_input = input("Input: ")
    print("Output:")
    f = Figlet(font=arg)
    print(f.renderText(usr_input))

def get_arguments():
    figlet = Figlet()
    if len(argv) == 1:
        fonts = figlet.getFonts()
        random_font = random.randint(0, len(fonts))
        return fonts[random_font]
    elif len(argv) == 3 and argv[1].lower() in ["-f", "--font"]:
        return argv[-1]
    
        
main()