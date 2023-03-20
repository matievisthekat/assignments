import java.io.*;
import java.util.*;

class Node {
   public int iData;
   public char cData;
   public Node leftChild;
   public Node rightChild;

   public void displayNode() {
       System.out.print('{');
       System.out.print(cData);
       System.out.print("} ");
   }
}
class Tree
   {
   private Node root;
   public Tree()
      { root = null; }

   public Node find(int key)
      {
      Node current = root;
      while(current.iData != key)
         {
         if(key < current.cData)
            current = current.leftChild;
         else
            current = current.rightChild;
         if(current == null)
            return null;
         }
      return current;
      }
      
      public void insert(int id, char c) {
         Node newNode = new Node();
         newNode.cData = c;
         newNode.iData = id;
         if (root == null) {
             root = newNode;
         } else {
             Node current = root;
             Node parent;
             while (true) {
                 parent = current;
                 if (current.leftChild == null) {
                     current = current.leftChild;
                     if (current == null) {
                         parent.leftChild = newNode;
                         return;
                     }
                 } else if (current.rightChild == null) {
                     current = current.rightChild;
                     if (current == null) {
                         parent.rightChild = newNode;
                         return;
                     }
                 } else {
                     current = current.leftChild;
                 }
             }
         }
     }

   public boolean delete(int key)
      {
      Node current = root;
      Node parent = root;
      boolean isLeftChild = true;

      while(current.iData != key)
         {
         parent = current;
         if(key < current.iData)
            {
            isLeftChild = true;
            current = current.leftChild;
            }
         else
            {
            isLeftChild = false;
            current = current.rightChild;
            }
         if(current == null)             
            return false;                
         }  
      
      if(current.leftChild==null &&
                                   current.rightChild==null)
         {
         if(current == root)             
            root = null;                 
         else if(isLeftChild)
            parent.leftChild = null;     
         else                            
            parent.rightChild = null;
         }
      
      else if(current.rightChild==null)
         if(current == root)
            root = current.leftChild;
         else if(isLeftChild)
            parent.leftChild = current.leftChild;
         else
            parent.rightChild = current.leftChild;

      else if(current.leftChild==null)
         if(current == root)
            root = current.rightChild;
         else if(isLeftChild)
            parent.leftChild = current.rightChild;
         else
            parent.rightChild = current.rightChild;

      else  
         {
         Node successor = getSuccessor(current);
         
         if(current == root)
            root = successor;
         else if(isLeftChild)
            parent.leftChild = successor;
         else
            parent.rightChild = successor;

         successor.leftChild = current.leftChild;
         }  
      
      return true;                                
      } 
   
   private Node getSuccessor(Node delNode)
      {
      Node successorParent = delNode;
      Node successor = delNode;
      Node current = delNode.rightChild;   
      while(current != null)               
         {                                 
         successorParent = successor;
         successor = current;
         current = current.leftChild;      
         }
                                           
      if(successor != delNode.rightChild)  
         {                                 
         successorParent.leftChild = successor.rightChild;
         successor.rightChild = delNode.rightChild;
         }
      return successor;
      }

   public void traverse(int traverseType)
      {
      switch(traverseType)
         {
         case 1: System.out.print("\nPreorder traversal: ");
                 preOrder(root);
                 break;
         case 2: System.out.print("\nInorder traversal:  ");
                 inOrder(root);
                 break;
         case 3: System.out.print("\nPostorder traversal: ");
                 postOrder(root);
                 break;
         }
      System.out.println();
      }

   private void preOrder(Node localRoot)
      {
      if(localRoot != null)
         {
         System.out.print(localRoot.iData + " ");
         preOrder(localRoot.leftChild);
         preOrder(localRoot.rightChild);
         }
      }

   private void inOrder(Node localRoot)
      {
      if(localRoot != null)
         {
         inOrder(localRoot.leftChild);
         System.out.print(localRoot.iData + " ");
         inOrder(localRoot.rightChild);
         }
      }

   private void postOrder(Node localRoot)
      {
      if(localRoot != null)
         {
         postOrder(localRoot.leftChild);
         postOrder(localRoot.rightChild);
         System.out.print(localRoot.iData + " ");
         }
      }

      public void displayTree() {
         Stack<Node> globalStack = new Stack<>();
         globalStack.push(root);
         int nBlanks = 32;
         boolean isRowEmpty = false;
         System.out.println("......................................................................");
 
         while (!isRowEmpty) {
             Stack<Node> localStack = new Stack<>();
             isRowEmpty = true;
 
             for (int j = 0; j < nBlanks; j++) {
                 System.out.print(' ');
             }
 
             while (!globalStack.isEmpty()) {
                 Node temp = globalStack.pop();
                 if (temp != null) {
                     System.out.print(temp.cData);
                     localStack.push(temp.leftChild);
                     localStack.push(temp.rightChild);
 
                     if (temp.leftChild != null || temp.rightChild != null) {
                         isRowEmpty = false;
                     }
                 } else {
                     System.out.print("--");
                     localStack.push(null);
                     localStack.push(null);
                 }
 
                 for (int j = 0; j < nBlanks * 2 - 2; j++) {
                     System.out.print(' ');
                 }
             }
             System.out.println();
             nBlanks /= 2;
             while (!localStack.isEmpty()) {
                 globalStack.push(localStack.pop());
             }
         }
         System.out.println("......................................................................");
     }
   }

class TreeApp
   {
   public static void main(String[] args) throws IOException
      {
      char value;
      int id;
      Tree theTree = new Tree();

      theTree.insert(54, 'A');
      theTree.insert(23, 'B');
      theTree.insert(99, 'C');
      theTree.insert(12, 'D');
      theTree.insert(78, 'E');
      theTree.insert(90, 'F');
      theTree.insert(2, 'G');
      theTree.insert(100, 'H');
      theTree.insert(43, 'I');
      theTree.insert(77, 'J');
      theTree.insert(11, 'K');
      while(true)
         {
         System.out.print("Enter first letter of show, ");
         System.out.print("insert, find, delete, or traverse: ");
         int choice = getChar();
         switch(choice)
            {
            case 's':
               theTree.displayTree();
               break;
            case 'i':
               System.out.print("Enter value to insert: ");
               value = getChar();
               System.out.print("Enter id for that value: ");
               id = getInt();
               theTree.insert(id, value);
               break;
            case 'f':
               System.out.print("Enter id to find: ");
               id = getInt();
               Node found = theTree.find(id);
               if(found != null)
                  {
                  System.out.print("Found: ");
                  found.displayNode();
                  System.out.print("\n");
                  }
               else
                  System.out.print("Could not find ");
                  System.out.print(id + '\n');
               break;
            case 'd':
               System.out.print("Enter value to delete: ");
               id = getInt();
               boolean didDelete = theTree.delete(id);
               if(didDelete)
                  System.out.print("Deleted " + id + '\n');
               else
                  System.out.print("Could not delete ");
                  System.out.print(id + '\n');
               break;
            case 't':
               System.out.print("Enter type 1, 2 or 3: ");
               value = getChar();
               theTree.traverse(value);
               break;
            default:
               System.out.print("Invalid entry\n");
            }  
         }  
      }  

   public static String getString() throws IOException
      {
      InputStreamReader isr = new InputStreamReader(System.in);
      BufferedReader br = new BufferedReader(isr);
      String s = br.readLine();
      return s;
      }

   public static char getChar() throws IOException
      {
      String s = getString();
      return s.charAt(0);
      }

   public static int getInt() throws IOException
      {
      String s = getString();
      return Integer.parseInt(s);
      }

   }
