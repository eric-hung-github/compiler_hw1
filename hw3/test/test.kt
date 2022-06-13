class Test {

    fun checkPrimeNumber(num: int): int {

        return 0
    }

    fun main() {
        var low = 20
        val high = 50

        while (low < high) {
            var result = checkPrimeNumber(low) 
            if (result==1)
                println(low)

            low = low + 1
        }
    }


}