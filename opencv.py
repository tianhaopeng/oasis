import cv2 as cv
import socket
import os
from PIL import Image as Img
import datetime

import threading
import time
import socket

exitFlag = 0
selfPath = os.path.split(os.path.abspath(__file__))[0]
cap = cv.VideoCapture(0)
name = ''
user = ''

class Opencv(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self.setDaemon(True)
        self.flag = 0
        self.videoFlag = False
        self.out = ''
        self.start()
    def run(self):
        while True:
            if self.flag == 1:
                save(getImg(),nowTime())
                self.flag = 0
            elif self.flag == 2:
                if self.videoFlag:
                    self.videoFlag = False
                    self.out.release()
                else:
                    self.videoFlag = True
                    path = selfPath+'\\video_image\\'+user+'-'+name+'-'+nowTime()+'.avi'
                    self.out = cv.VideoWriter(path,cv.VideoWriter_fourcc(*'XVID'),30.0,(640,480))
                self.flag = 0
            if self.videoFlag:
                self.out.write(getFrame())
    def __del__(self):
        cap.release()


#out = cv.VideoWriter('h264_1.mp4',cv.VideoWriter_fourcc('H', '2', '6', '4'),30.0,(640,480))
#out.write(frame)
#out.release()

def save(bs,path = '1'):
    path = selfPath+'\\video_image\\'+user+'-'+name+'-'+path+'.jpg'
    with open(path,'ab') as ds:
        ds.write(bs)
        ds.close()
def get(path = 'F:/1.jpg'):
    with open(path,'rb') as ds:
        ts = ds.read()
        ds.close()
        return ts

def nowTime():
    return datetime.datetime.now().strftime('%Y-%m-%d-%H_%M_%S')

def ptime():
    print('时间：',datetime.datetime.now().strftime('%Y-%m-%d-%H:%M:%S.%f'))

def getFrame():
    ret,frame = cap.read()
    return frame

def getImg():
    ret,frame = cap.read()
    bs = cv.imencode(".jpg",frame)[1].tobytes()
    return bs


def cvsave():
    ret,frame = cap.read()
    bs = cv.imencode(".jpg",frame)[1].tobytes()
    print(len(bs))
    save(bs)

def quit():
    cap.release()

if __name__ == "__main__":
    opencv = Opencv()
    
    serversocket = socket.socket(
            socket.AF_INET, socket.SOCK_STREAM)
    serversocket.bind(("0.0.0.0", 5599))
    serversocket.listen(5)
    while exitFlag == 0:
        clientsocket,addr = serversocket.accept()
        nu = clientsocket.recv(1024).decode('utf8').split('~*~')
        name = nu[0]
        user = nu[1]
        clientsocket.settimeout(0.03)
        timeout = 0
        while True:
            img = getImg()
            try:
                clientsocket.sendall(str(len(img)).encode('utf8'))
                clientsocket.sendall(img)
            except:
                print("timeout",timeout)
                timeout += 1
            try:
                data = clientsocket.recv(1024)
            except:
                continue
            if data == b"" or data == b"q":
                exitFlag == 1
                os._exit(0)
                break
            elif data == b"1":
                opencv.flag = 1
            elif data == b"2":
                opencv.flag = 2
        clientsocket.close()
    #quit()
