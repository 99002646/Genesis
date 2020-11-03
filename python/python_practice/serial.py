import pickle;
class Image():
    def __init__(self):
        self.i=10;
        self.f=12.34;
        self.s="test data";
        self.b=True;

    def process(self):
        self.image_res="IDENTIFIED";
'''
img=Image();
img.process();
print(img.image_res);
file=open("Image.dat","wb");
pickle.dump(img,file);
file.close();
'''
file=open("Image.dat","rb");
img2=pickle.load(file);
print("type of imge2::",type(img2));
print(img2.image_res);


'''
class Test():
    def __init__(self):
        self.i=10;
        self.f=12.34;
        self.s="test data";
        self.b=True;
t1 = Test();
t1_b=pickle.dumps(t1);
print(t1_b);
t2=pickle.loads(t1_b);
print(t2.f);
print(t2.s);
'''
'''
L1=list(range(100));

L1_B=pickle.dumps(L1);
print(L1_B);
L2=pickle.loads(L1_B);

print("--------------");
print(type(L2));
print(L2);
'''