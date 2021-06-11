class BiTreeNode {
    value: number;
    count: number = 1;
    leftCount: number = 0;
    rightCount: number = 0;
    children: BiTreeNode[] =[undefined, undefined];
    constructor(v){
        this.value = v;
    }
}

class BinaryTree {
    root: BiTreeNode;
    
    put(v: number){
        let target = new BiTreeNode(v);
        let sum = 0;

        if(!this.root){
            this.root = target;
            return sum;
        }
        
        let prev: BiTreeNode;
        let iter: BiTreeNode = this.root;
        let childIndex = 0;

        while(iter){
            if(iter.value === v){
                iter.count++;
                sum += iter.leftCount;
                return sum;
            }
            prev = iter;
            if(iter.value < v){
                iter.rightCount++;
                sum+=(iter.leftCount + iter.count);
                childIndex = 1;
            } else {
                iter.leftCount++;
                childIndex = 0;
            }
            iter = iter.children[childIndex];            
        }
        prev.children[childIndex] = target;
        return sum;
    }

}



function countSmaller(nums: number[]): number[] {
    let counts=[];
    let size = nums.length;
    let binaryTree = new BinaryTree();
    for(let i = size-1; i>=0; --i ){
        counts.push(binaryTree.put(nums[i]));  
    }
    
    return counts.reverse();
};