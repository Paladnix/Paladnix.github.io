#!/usr/local/bin/python3
# coding=utf-8

import fitz
import os
import sys
from PIL import Image
import shutil


'''
# 将PDF转化为图片
pdfPath pdf文件的路径
imgPath 图像要保存的文件夹
zoom_x x方向的缩放系数
zoom_y y方向的缩放系数
rotation_angle 旋转角度
'''


def make_dir(path):
    folder = os.path.exists(path)
    if not folder:
        os.makedirs(path)
        print("create new folder: " + path)
    else:
        shutil.rmtree(path)
        os.makedirs(path)
        print("recreate folder: " + path)

def pdf_image(pdfPath):
    imgPath = "./imgPath-tmp/"
    make_dir(imgPath)
    # 打开PDF文件
    pdf = fitz.open(pdfPath)
    # 逐页读取PDF#

    for pg in range(pdf.page_count):
        # 设置缩#放和旋转系数
        page = pdf.load_page(pg)
        rotate = int(0)
        # 每个尺寸的缩放系数为1.3，这将为我们生成分辨率提高2.6的图像。
        # 此处若是不做设置，默认图片大小为：792X612, dpi=96
        zoom_x = 4#(1.33333333-->1056x816)   (2-->1584x1224)
        zoom_y = 4
        mat = fitz.Matrix(zoom_x, zoom_y).prerotate(rotate)
        pix = page.get_pixmap(matrix=mat, alpha=False)
        pix.pil_save(imgPath+str(pg)+".png")
    pdf.close()
    generate_long_image(imgPath)
             
'''          
将上一步生成的图片合成为长#图
output_path为长#图的输出路径
'''          
             
def generate_long_image(imgPath):

    picture_path = "./"

    imagename = []
    ims = []
    # 获取单个图片存到list集合
    file_list = os.listdir(imgPath)
    file_list.sort(key=lambda x: int(x[:-4]))

    for fn in file_list:
         if fn.endswith('.png'):
            ims.append(Image.open(os.path.join(imgPath, fn)))
            imagename.append(os.path.join(imgPath, fn))
          
    width, height = ims[0].size  # 取第一个图片尺寸
    long_canvas = Image.new(ims[0].mode, (width, height * len(ims)))  # 创建同宽，n高的白图片

    # 拼接图片
    for i, image in enumerate(ims):
        long_canvas.paste(image, box=(0, i * height))

    for j, name in  enumerate(imagename): 
        os.remove(name)  
        
    long_canvas.save(os.path.join(picture_path, 'long-image.png'))  # 保存长图
    

pdf_image(sys.argv[1])


