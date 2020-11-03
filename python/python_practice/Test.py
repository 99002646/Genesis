

class Test():
    def __init__(self):
        self.i=10;
        self.f=12.24;
        self.t="test data";
        print("initt");
    def display(self):
       self.i=10; 
       print("I-",self.i)

    def show_i(self):
        print("show module",self.i);

t1=Test();
t1.display();#ti.display(ti);

t1.show_i();
t2=Test();
t2.show_i();
