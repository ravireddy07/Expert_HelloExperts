import java.util.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.ArrayList;


class ProducerConsumer {
    public static void main(String[] args) throws Exception {
        Queue<Integer> queue = new LinkedList<>();
        Integer buffer = new Integer(10);  //Important buffer or queue size, change as per need.

        Producer producerThread = new Producer(queue, buffer, "PRODUCER");
        Consumer consumerThread = new Consumer(queue, buffer, "CONSUMER");

        producerThread.start();  
        consumerThread.start();
    }   
}

class Producer extends Thread {
    private Queue<Integer> queue;
    private int queueSize ;

    public Producer (Queue<Integer> queueIn, int queueSizeIn, String ThreadName){
        super(ThreadName);
        this.queue = queueIn;
        this.queueSize = queueSizeIn;
    }

    public void run() {
        while(true){
            synchronized (queue) {
                while(queue.size() == queueSize){
                    System.out.println(Thread.currentThread().getName() + " FULL         : waiting...\n");
                    try{
                        queue.wait();   //Important
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }
                }

                //queue empty then produce one, add and notify  
                int randomInt = new Random().nextInt(); 
                System.out.println(Thread.currentThread().getName() + " producing... : " + randomInt); 
                queue.add(randomInt); 
                queue.notifyAll();  //Important
            } //synchronized ends here : NOTE
        }
    }
}

class Consumer extends Thread {
    private Queue<Integer> queue;
    private int queueSize;

    public Consumer(Queue<Integer> queueIn, int queueSizeIn, String ThreadName){
        super (ThreadName);
        this.queue = queueIn;
        this.queueSize = queueSizeIn;
    }

    public void run() {
        while(true){
            synchronized (queue) {
                while(queue.isEmpty()){
                    System.out.println(Thread.currentThread().getName() + " Empty        : waiting...\n");
                    try {
                        queue.wait();  //Important
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }
                }

                //queue not empty then consume one and notify
                System.out.println(Thread.currentThread().getName() + " consuming... : " + queue.remove());
                queue.notifyAll();
            } //synchronized ends here : NOTE
        }
    }
}