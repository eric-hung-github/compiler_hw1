class Test {

    var low = 20
    val high = 100

    fun checkPrimeNumber(num: int): int {

        for (i in 2..(num/2) ) {

            if (num % i == 0) {
                return 0
            }
            i = i + 1
        }

        return 1
    }

    fun main() {

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