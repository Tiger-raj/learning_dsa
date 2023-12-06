import java.util.*;

class Parent
{
    int n;
    Parent()
    {
        this.n = 5;
    }
    void fun(){
        System.out.println("I'm in Parent");
    }
};

class Child extends Parent
{
    int n;
    Child(int n)
    {
        super();
        this.n = n;
    }
     void fun(){
        System.out.println("I'm in Child");
    }
};

public class inheritance{
    public static void main(String[] args){
        Parent obj = new Child(10);
        System.out.println(obj.n);
        obj.fun();
    }
}