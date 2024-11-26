import os
from PIL import Image

def ConvertPngToBmpWithAlpha(pngFilePath, bmpFilePath):
    with Image.open(pngFilePath) as img:
        if img.mode != 'RGBA':         # Ensure the image has an alpha channel
            img = img.convert('RGBA')
        alpha = img.split()[3]
        bmp_image = Image.new('RGBA', img.size)
        bmp_image.paste(img, (0, 0), mask=alpha)
        bmp_image.save(bmpFilePath, 'BMP')

def ProcessDirectory(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.lower().endswith('.png'):
                pngFilePath = os.path.join(root, file)
                bmpFilePath = os.path.splitext(pngFilePath)[0] + '.bmp'
                ConvertPngToBmpWithAlpha(pngFilePath, bmpFilePath)
                print(f"Converted '{pngFilePath}' to '{bmpFilePath}'")

def main():
    currentDirectory = os.getcwd()
    ProcessDirectory(currentDirectory)

if __name__ == '__main__':
    ConvertPngToBmpWithAlpha('scripts/test.png', 'scripts/test.bmp')
