#include <string>
using namespace std;


template<typename V>
class MapNode {
    public:

    string key;
    V value;
    MapNode * next;

    MapNode(string key, V value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    ~MapNode(){
        delete next;
    }
};

template<typename V>
class ourMap {
    MapNode<V>* * buckets;
    int count;
    int numBuckets;

    // O(l) ; l -> length of key
    int getBucketIndex(string key) { // to provide the index using hash function
        int hashCode = 0;

        int currentCoefficient = 1;
        // using“abcd”=(‘a’*p​3)​ +(‘b’*p2​ )​ +(‘c’*p​1)​ +(‘d’*p​0)​ as our hashcode
        for(int i=key.size() - 1; i>= 0; i--){
            hashCode += key[i] * currentCoefficient;
            // just to keep it in bounds (modular exponentiation prop)
            hashCode = hashCode % numBuckets;  

            currentCoefficient *= 37; // prime = 37
            // just to keep it in bounds (modular exponentiation prop)
            currentCoefficient = currentCoefficient % numBuckets;
        }

        // Compression
        return hashCode % numBuckets;
    }

    void rehash() {
        MapNode<V>* * temp = buckets;
        buckets = new MapNode<V>*[2 * numBuckets];
        int oldNumBuckets = numBuckets;
        numBuckets *= 2;
        count = 0;

        for(int i=0; i<numBuckets; i++) buckets[i] = NULL;

        for(int i=0; i<oldNumBuckets; i++){
            MapNode<V>* head = temp[i];

            while(head != NULL){
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        
        // deleting temp array
        for(int i=0; i<oldNumBuckets; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }

    public:

    ourMap() {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];

        for(int i=0; i<numBuckets; i++) buckets[i] = NULL;

    }

    ~ourMap() {
        for(int i=0; i<numBuckets; i++) delete buckets[i];

        delete [] buckets;
    }

    int size() { return count;}

    V getValue(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];

        while(head != NULL) {
            if(head->key == key){
                return head->value;
            }

            head = head->next;
        }

        return INT_MIN;  // Not found
    }

    // load factor(l.f.) = Number of entires (N)/ Number of buckets (B or numbuckets)
    // l.f. <= 0.7
    // O(l.f.)
    // As N increases l.f. decreases, to maintain l.f. we increase B, by 
    // doubling the size of buckets -> Rehashing
    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];

        while(head != NULL) {
            if(head->key == key){
                head->value = value;
                return;
            }

            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<V>* newNode = new MapNode<V>(key, value);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++;

        // Check for rehashing
        double loadFactor = (1.0 * count) / numBuckets;
        if(loadFactor > 0.7){
            rehash();
        }
    }

    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;

        while(head != NULL) {
            if(head->key == key) {
                if(prev == NULL) {
                    buckets[bucketIndex] = head->next;
                } else {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;  // so as to avoid deletion of entire chain
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }

        return INT_MIN;
    }
};