public class Multiplication {
  public static int mult(int x, int y) {
      if (y == 0) {
          return 0;
      } else {
          return x + mult(x, y - 1);
      }
  }
  
  public static void main(String[] args) {
      int x = 5;
      int y = 7;
      int result = mult(x, y);
      System.out.println(x + " * " + y + " = " + result);
  }
}
