import java.util.Scanner;

class StackExceptions extends Exception {
    private String errorCode;

    StackExceptions(String err) {
        errorCode = err;
    }

    String getCode() {
        return errorCode;
    }
}

class Stack {
    private int arr[];
    private int tos;
    private int maxSize;

    StackExceptions stackFull = new StackExceptions("Stack Overflow");
    StackExceptions stackEmpty = new StackExceptions("Stack Underflow");

    Scanner sc = new Scanner(System.in);

    void initialiseTOS(int n) {
        maxSize = n;
        tos = -1;
        arr = new int[maxSize];
    }

    void push(int value) throws StackExceptions {
        if (tos == maxSize - 1) {
            throw stackFull;
        }
        arr[++tos] = value;
    }

    int pop() throws StackExceptions {
        if (tos == -1) {
            throw stackEmpty;
        }
        return arr[tos--];
    }
}

class Stack_Demo {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Stack s = new Stack();

        System.out.print("Enter max length of stack: ");
        int n = sc.nextInt();
        s.initialiseTOS(n);

        int input;
        int flag = 1;

        while (flag != 0) {
            System.out.print("Enter 1 for push, 2 for pop, and -1 to exit: ");
            input = sc.nextInt();

            try {
                if (input == 1) {
                    System.out.print("Enter integer to push: ");
                    int value = sc.nextInt();
                    s.push(value);
                } else if (input == 2) {
                    System.out.println("Integer popped is: " + s.pop());
                } else if (input == -1) {
                    System.out.println("Exiting");
                    flag = 0;
                } else {
                    System.out.println("Invalid input.");
                }
            } catch (StackExceptions e) {
                System.out.println("Error: " + e.getCode());
            }
        }
    }
}

