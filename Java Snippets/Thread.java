public class Example {
    public static class ThreadExample extends Thread {
        int count = 0;
        public void run() {
            System.out.println("We are starting!");
            try {
                while (count < 5) {
                    Thread.sleep(500);
                    System.out.println("In thread - " + count);
                    count++;
                }
            } catch (InterruptedException ex) {
                System.out.println("Thread interrupted!");
            }
            System.out.println("Thread ended!");
        }
    }
    public static void main(String args[]) {
        ThreadExample instance = new ThreadExample();
        instance.start();
        
        while(instance.count != 5) {
            try {
                Thread.sleep(250);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }
}
