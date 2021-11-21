class QueueNode {
    constructor(val) {
        this.val  = val;
        this.next = null;
    }
}

class Queue {
    constructor() {
        this.first = null;
        this.last   = null;
    }
    
    push(val) {
        if(this.last)
            this.last.next = new QueueNode(val);
        else {
            this.last = new QueueNode(val);
            this.first = this.last;
        }
            
        if(this.last.next)
           this.last = this.last.next;
    }
    
    front() {
        if(this.first == null) {
            return null;
        }

        let val = this.first.val;
        this.first = this.first.next;

        return val;
    }
}

// let queue = new Queue();

// queue.push(10);
// queue.push(20);
// queue.push(30);

// console.log(queue);

// console.log("front: " + queue.front());
// console.log("front: " + queue.front());

// queue.push(40);

// console.log("front: " + queue.front());
// console.log("front: " + queue.front());
// console.log("front: " + queue.front());
