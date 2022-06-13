class Test {

    fun checkPrimeNumber(num: int): int {
        println(num)

        num = num / 2

        var i = 2


        while (i <= num ) {
            print(i)
            print(" ")

            var is_prime = num % i

            if (is_prime == 0) {
                return 0
            }
            i = i + 1
        }

        println(" ")

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

            low = low + 1
        }
    }


}