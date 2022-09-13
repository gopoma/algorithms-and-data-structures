class Node {
    constructor(value) {
        this.value = value;
    }

    static isLeaf() {
        return this.left === undefined && this.right === undefined;
    }
}

class BST {
    add(value) {
        try {
            this.root = this.#addNode(value, this.root);
            return {success: true};
        } catch ({message}) {
            return {
                success: false,
                message
            };
        }
    }
    #addNode(value, current) {
        if(current === undefined) {
            current = new Node(value);
        } else {
            if(value > current.value) {
                current.right = this.#addNode(value, current.right);
            } else if(value < current.value) {
                current.left = this.#addNode(value, current.left);
            } else {
                throw new Error("Can't insert a duplicate value!");
            }
        }
        return current;
    }

    getMinValue() {
        return this.root !== undefined ? this.#getMinNodeValue(this.root) : "There are no Nodes!";
    }

    #getMinNodeValue(current) {
        return current.left === undefined ? current.value : this.#getMinNodeValue(current.left);
    }
    delete(value) {
        try {
            this.root = this.#deleteNode(value, this.root);
            return {success: true};
        } catch ({message}) {
            return {
                success: false,
                message
            };
        }
    }
    #deleteNode(value, current) {
        if(current === undefined) {
            throw new Error("Not Found!");
        } else {
            if(value > current.value) {
                current.right = this.#deleteNode(value, current.right);
            } else if(value < current.value) {
                current.left = this.#deleteNode(value, current.left);
            } else {
                if(current.left !== undefined && current.right !== undefined) {
                    const minRight = this.#getMinNodeValue(current.right);
                    current.value = minRight;
                    current.right = this.#deleteNode(minRight, current.right);
                } else {
                    current = current.left !== undefined ? current.left : current.right;
                }
            }
        }
        return current;
    }

    preOrder() {
        return this.root !== undefined ? this.#preOrderNode(this.root).trim() : "There are no Nodes!";
    }
    #preOrderNode(current) {
        let result = "";
        result += current.value + " ";
        if(current.left !== undefined) {
            const partial = this.#preOrderNode(current.left);
            result += partial.endsWith(" ") ? partial : partial + " ";
        }
        if(current.right !== undefined) {
            const partial = this.#preOrderNode(current.right);
            result += partial.endsWith(" ") ? partial : partial + " ";
        }
        return result;
    }

    inOrder() {
        return this.root !== undefined ? this.#inOrderNode(this.root).trim() : "There are no Nodes!";
    }
    #inOrderNode(current) {
        let result = "";
        if(current.left !== undefined) {
            const partial = this.#inOrderNode(current.left);
            result += partial.endsWith(" ") ? partial : partial + " ";
        }
        result += current.value + " ";
        if(current.right !== undefined) {
            const partial = this.#inOrderNode(current.right);
            result += partial.endsWith(" ") ? partial : partial + " ";
        }
        return result;
    }

    postOrder() {
        return this.root !== undefined ? this.#postOrderNode(this.root).trim() : "There are no Nodes!";
    }
    #postOrderNode(current) {
        let result = "";
        if(current.left !== undefined) {
            const partial = this.#postOrderNode(current.left);
            result += partial.endsWith(" ") ? partial : partial + " ";
        }
        if(current.right !== undefined) {
            const partial = this.#postOrderNode(current.right);
            result += partial.endsWith(" ") ? partial : partial + " ";
        }
        return result + current.value + " ";
    }
}

module.exports = BST;