const GraphMatrix = require("../models/GraphMatrix");

const Chai = require("chai");
const { expect } = Chai;

// eslint-disable-next-line
describe("GraphMatrix", () => {
    // eslint-disable-next-line
    it("Case 1: Depth First Search (DFS)", () => {
        const graph = new GraphMatrix(6);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(0, 3);
        graph.addEdge(0, 4);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        graph.addEdge(2, 4);

        const result = graph.depthFirstSearch(0);
        expect(result).to.be.eql([0, 1, 2, 3, 4]);
    });
    // eslint-disable-next-line
    it("Case 2: Connected Components", () => {
        const graph = new GraphMatrix(6);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(0, 3);
        graph.addEdge(0, 4);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        graph.addEdge(2, 4);

        const result = graph.countConnectedComponents();
        expect(result).to.be.a("number");
        expect(result).to.be.equal(2);
    });
    // eslint-disable-next-line
    it("Case 3: Connected Components", () => {
        const graph = new GraphMatrix(5);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(0, 3);
        graph.addEdge(0, 4);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        graph.addEdge(2, 4);

        const result = graph.countConnectedComponents();
        expect(result).to.be.a("number");
        expect(result).to.be.equal(1);
    });
    // eslint-disable-next-line
    it("Case 4: Connected Components", () => {
        const graph = new GraphMatrix(5);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(0, 3);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        const result = graph.countConnectedComponents();

        expect(result).to.be.a("number");
        expect(result).to.be.equal(2);
    });
    // eslint-disable-next-line
    it("Case 5: Connected Components", () => {
        const graph = new GraphMatrix(5);
        const result = graph.countConnectedComponents();

        expect(result).to.be.a("number");
        expect(result).to.be.equal(5);
    });
    // eslint-disable-next-line
    it("Case 6: Empty Graph", () => {
        const graph = new GraphMatrix();

        const result = graph.countConnectedComponents();
        expect(result).to.be.a("number");
        expect(result).to.be.equal(0);
        expect(graph.depthFirstSearch(200)).to.have.property("success", false);
        expect(graph.depthFirstSearch(200)).to.have.property("message", "Graph is Empty!");
    });
});