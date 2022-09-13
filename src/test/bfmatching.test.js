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
    it("Case 3", () => {

    });
});