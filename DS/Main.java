import java.util.Scanner;

class LinkedList{
    Node head;

    class Node{
        int data;
        Node next;
        Node(int d){
            data = d;
            next = null;
        }
    }

    void print(String s){
        System.out.print(s);
    }
    void println(String s){
       System.out.println(s);
    }

    public void push(int data){
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
        println("node inserted");
    }

    public void insertAfter(Node prevNode, int data){
        if(prevNode == null){
            System.out.println("Previous node does not exist\n");
            return;
        }

        Node newNode = new Node(data);
        newNode.next = prevNode.next;
        prevNode.next = newNode;
        println("node inserted");
    }

    public void append(int data){
        Node newNode = new Node(data);
        if(head == null){
            head = new Node(data);
            println("node inserted");
            return;
        }
        newNode.next = null;

        Node last = head;
        while(last.next != null){
            last = last.next;
        }
        last.next = newNode;
        println("node inserted");
        return;
    }

    public void displayList(){
        Node pNode = head;
        while(pNode != null){
            System.out.print(pNode.data + "-->");
            pNode = pNode.next;
        }
        if(pNode == null){
            System.out.println("null");
        }
    }

    public void insertAfterNode(int prev, int data){
        Node pNode = head;
        Node prevNode = null;
        while(pNode != null){
            if(pNode.data == prev){
                prevNode = pNode;
                break;
            }
                pNode = pNode.next;
        }
        insertAfter(prevNode, data);
    }
}



class Main{

    static void print(String s){
        System.out.print(s);
    }

    static void println(String s){
       System.out.println(s);
    }

    public static void main(String[] args){
        LinkedList List = new LinkedList();
        Scanner sc = new Scanner(System.in);
        int ch,ch2,data, prev;
        char ch3 = 'n';

    do{

        println("Enter your choice: ");
        println("1.Insert");
        println("2.Delete");
        println("3.Display");
        ch = sc.nextInt();

        switch(ch){
            case 1:
                println("1.Insert at front.");
                println("2.Insert at last.");
                println("3.Insert in between.");
                ch2 = sc.nextInt();
                switch(ch2){
                    case 1:
                        println("Enter data: ");
                        data = sc.nextInt();
                        List.push(data);
                        break;
                    case 2:
                        println("Enter data: ");
                        data = sc.nextInt();
                        List.append(data);
                        break;
                    case 3:
                        println("Enter data: ");
                        data = sc.nextInt();
                        println("Enter number after which the data to be inserted: ");
                        prev = sc.nextInt();
                        List.insertAfterNode(prev,data);
                        break;
                }
                break;
            case 2:
                break;
            case 3:
                List.displayList();
                break;
            default:
                break;
        }
        println("do you want to continue(y/n)?");
        ch3 = sc.next().charAt(0);
    }while(ch3 == 'y');
    }
}