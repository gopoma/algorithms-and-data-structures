const bfmatching = require("../functions/bfmatching");

const Chai = require("chai");
const expect = Chai.expect;

// eslint-disable-next-line
describe("Pattern Matching: Brute Force Strategy", () => {
    // eslint-disable-next-line
    it("Case 1", () => {
        const result = bfmatching("JavaScript is a good programming language", "good");
        expect(result).to.be.a.true;
    });
    // eslint-disable-next-line
    it("Case 2", () => {
        const result = bfmatching("TypeScript is a growing language that are making a standart in the industry", "JavaScript");
        expect(result).to.be.false;
    });
    // eslint-disable-next-line
    it("Case 3", () => {
        const result = bfmatching("Data Structures", "Algorithms");
        expect(result).to.be.false;
    });
    // eslint-disable-next-line
    it("Case 4", () => {
        const result = bfmatching("This is a common text", "Thi");
        expect(result).to.be.true;
    });
    // eslint-disable-next-line
    it("Case 5", () => {
        const result = bfmatching("This is a cmmon text", "Thx");
        expect(result).to.be.false;
    });
    // eslint-disable-next-line
    it("Case 6", () => {
        const result = bfmatching("This is a common text", "ext");
        expect(result).to.be.true;
    });
    // eslint-disable-next-line
    it("Case 7", () => {
        const result = bfmatching("This is a common text", "fexty");
        expect(result).to.be.false;
    });
    // eslint-disable-next-line
    it("Case 8", () => {
        const result = bfmatching("aaaaaaaaaa", "aaa");
        expect(result).to.be.true;
    });
    // eslint-disable-next-line
    it("Case 9", () => {
        const result = bfmatching("aaaaaaaaaa", "aaax");
        expect(result).to.be.false;
    });
    // eslint-disable-next-line
    it("Case 10", () => {
        const result = bfmatching("algorithms", "algorithms");
        expect(result).to.be.true;
    });
    // eslint-disable-next-line
    it("Case 11", () => {
        const result = bfmatching("Data Structures", "data");
        expect(result).to.be.false;
    });
    // eslint-disable-next-line
    it("Case 12", () => {
        const result = bfmatching("Data Structures", "data structures");
        expect(result).to.be.false;
    });
});