const BST = require("../models/BST");

const Chai = require("chai");
const expect = Chai.expect;

// eslint-disable-next-line
describe("BST", () => {
    // eslint-disable-next-line
    it("Case 1", () => {
        const tree = new BST();
        tree.add(4);
        tree.add(2);
        tree.add(1);
        tree.add(3);
        tree.add(5);
        tree.add(6);
        const preOrder = tree.preOrder();
        const inOrder = tree.inOrder();
        const postOrder = tree.postOrder();

        expect(preOrder).to.be.a("string");
        expect(preOrder).to.be.equal("4-2-1-3-5-6");
        expect(inOrder).to.be.a("string");
        expect(inOrder).to.be.equal("1-2-3-4-5-6");
        expect(postOrder).to.be.a("string");
        expect(postOrder).to.be.equal("1-3-2-6-5-4");
    });
    // eslint-disable-next-line
    it("Case 2", () => {
        const tree = new BST();
        tree.add(4);
        tree.add(2);
        tree.add(1);
        tree.add(0);
        tree.add(1.5);
        tree.add(1.32);
        tree.add(3);
        tree.add(2.5);
        tree.add(2.8);
        tree.add(2.56);
        tree.add(2.95);
        tree.add(3.5);
        tree.add(5);
        tree.add(6);
        tree.add(7);
        const preOrder = tree.preOrder();
        const inOrder = tree.inOrder();
        const postOrder = tree.postOrder();

        expect(preOrder).to.be.a("string");
        expect(preOrder).to.be.equal("");
        expect(inOrder).to.be.a("string");
        expect(inOrder).to.be.equal("");
        expect(postOrder).to.be.a("string");
        expect(postOrder).to.be.equal("");
    });
    // eslint-disable-next-line
    it("Case 5: Empty BST", () => {
        const tree = new BST();
        const preOrder = tree.preOrder();
        const inOrder = tree.inOrder();
        const postOrder = tree.postOrder();

        expect(preOrder).to.be.a("string");
        expect(preOrder).to.be.equal("There are no Nodes!");
        expect(inOrder).to.be.a("string");
        expect(inOrder).to.be.equal("There are no Nodes!");
        expect(postOrder).to.be.a("string");
        expect(postOrder).to.be.equal("There are no Nodes!");
    });
});