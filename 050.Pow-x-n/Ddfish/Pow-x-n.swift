class Solution {
    func myPow(_ x: Double, _ n: Int) -> Double {
    
        if( x == 0 ) { return 0 }
        if( n == 0 ) { return 1 }
        if( n < 0 )  { return  1 / myPow(x,n*(-1))}
        let y = myPow(x, n/2)
        if n % 2 == 0 {
            return y * y
        }else {
            return x * y * y
        }


    }
}
