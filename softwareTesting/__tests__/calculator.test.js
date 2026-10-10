import { divide } from '../src/calculator.js';

describe('divide', () =>{
    it('divides two positive numbers', () => {
        expect(divide(2,1)).toBe(2);
    });

    it('Throws when divided by zero', () =>{
        expect(() => divide(2,0)).toThrow('Division by zero is not allowed');
    });

    it('Fails when inputs arent numbers', () =>{
        expect(() => divide(2,'1')).toThrow('Both arguments must be numbers');
    });

    it('Fails when input is NaN', () =>{
        expect(() => divide(2, Math.sqrt(-1))).toThrow('Arguments cannot be NaN');
    });

    it('Throws when arguments are infinite', () => {
        expect(() => divide(Infinity, Infinity - Infinity)).toThrow('Arguments cannot be NaN');
    });
})