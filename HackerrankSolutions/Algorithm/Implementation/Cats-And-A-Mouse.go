package main
import (
    "fmt"
    "math"
)

func printRes( arr[3] int ) {
    if int( math.Abs( float64(arr[2] - arr[0] ) ) ) < int(math.Abs( float64(arr[2] - arr[1]) ) ) {
        fmt.Println("Cat A")
    }else if int( math.Abs( float64(arr[2] - arr[0] ) ) ) > int(math.Abs( float64(arr[2] - arr[1]) ) ) {
        fmt.Println("Cat B")
    }else{
        fmt.Println("Mouse C")
    }
}

func main() {
    var q int
    _, _ = fmt.Scanf("%d", &q)
    var a [3]int
    for i := 0; i < q; i++ {
        _, _ = fmt.Scanf("%d %d %d", &a[0], &a[1], &a[2])
        printRes( a )
    }
}
