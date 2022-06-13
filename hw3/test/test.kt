class Test {

    fun checkPrimeNumber(num: int): int {
        println(num)

        var range: int
        var isprime: int

        var i = 2

        range = num / 2

        while (i <= range ) {
            print(i)

            isprime = num % i

            print(":")

            print(isprime)

            print(" ")


            if (isprime == 0) {
                println(" false ")
                return 0
            }
            i = i + 1
        }

        println(" true ")

        return 1
    }

    fun main() {
        var low = 20
        val high = 50
        var result:int

        while (low < high) {
            result = checkPrimeNumber(low) 
            if (result == 1){
                println(low)
            }
            println("===========")


            low = low + 1
        }
    }


}