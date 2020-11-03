class Number():
    def __init__(self,n=0):
        self.n=n;

    def display(self):
        print("N=",self.n);

    def __add__(self,other):
        print("Number.__add__");
        temp=Number();
        if(isinstance(other,Number)):
            temp.n=self.n+other.n;
        elif(isinstance(other,int)):
            print("int Received");
            temp.n=self.n;
        else:
            print("something else Received");
            
        return temp;


n1=Number(10);
n2=Number(20);
n1.display();
n3=n1+"";
print("n3 type is:",type(n3));
n1.display();
n2.display();
n3.display();