class Test {

    var low = 20
    val high = 200

    fun checkPrimeNumber(num: int): int {

        var i = 2

        while (i <= (num / 2) ) {

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