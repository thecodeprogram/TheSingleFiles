package javacalisma;

/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 17.10.2020
*/
public class BinarySearchTree {
    
   public static void main(String[] args) {
       
        JavaCalisma.BinarySearchTree bst = new JavaCalisma.BinarySearchTree();
        int[] data = {10, 11, 9, 6, 15, 2, 23, 14, 1};
        
        for(int i=0; i<data.length; i++){
            bst.add(data[i]);
        }
        
        boolean wasFound = bst.isNodeExist(15);
        bst.delete(15);
        System.out.println("");
        
    }
   
    public static class Node{
        int data;
        Node left = null;
        Node right = null;
        public Node(int data) { this.data = data; }
    }
    
    public static class BinarySearchTreeStructure{
    
        //first we need to create a root node
        Node rootNode;
        
        //Make public below private method
        public void add(int data) { rootNode = addNode(rootNode, data); }
        //This method will be recursive
        private Node addNode(Node current, int data){
            //Eğer herhangi bir node yoksa yeni oluştur
            if(current == null) return new Node(data);
            //eğer varsa gelenin değerine göre sağa veya sola gideceğine karar ver
            if(data < current.data) current.left = addNode(current.left, data);
            else if(data > current.data) current.right = addNode(current.right, data);
            //sağa sola gitmiyorsa eşittir o zaman eklenmez ve geri dönder
            else return current;
            
            return current;
        }
        
        public boolean isNodeExist(int data){ return findNode(rootNode, data); }
        
        private boolean findNode(Node current, int data){
            //eğer gelen node null ise false dönecek
            //eğer gelen değerdeki data ile bizim aradıgımız tutuyorsa true dönecek
            if(current == null) return false;
            if(data == current.data) return true;
            
            //eğer aramalarda çıkmadıysa aranan değere göre sağa veya sola gönder
            if(data < current.data) return findNode(current.left, data);
            else if(data > current.data) return findNode(current.right, data);
            
            return false;
        }
        
        public void delete(int data){ deleteNode(rootNode, data); }
        
        private Node deleteNode(Node current, int data){
            if(current==null) return null;
            if(data == current.data){
                //deletion process
                //if found node has no sub nodes set it as null directly
                if(current.left == null && current.right ==null){
                    return  null;
                }
                
                //if node has only one sub node kendisini null yap ve alt nodu buna ata
                if(current.right == null) return current.left;
                else if(current.left == null) return current.right;
                
                //DO NOT ASSIGN ONE OF NODES HERE, BECAUSE IT WILL REMOVE THE OTHER NODES
                if(current.left != null && current.right !=null){
                    int smallestData = findLeft(current.right);
                    current.data = smallestData;
                    current.right = deleteNode(current.right, smallestData);
                }
                
            }
            else if(data < current.data){
                current.left = deleteNode(current.left, data);
            }
            else if(data > current.data){
                current.right = deleteNode(current.right, data);
            }
            return current;
        }
        private int findLeft(Node node){
            return node.left == null ? node.data : findLeft(node);
        }
    }
    
}
