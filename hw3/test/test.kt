class Test {

    fun checkPrimeNumber(num: int): int {
        var flag = true
        num = num / 2
        for (i 2..num ) {

            if (num % i == 0) {
                flag = false
                return 1
            }
        }

        return 0
    }

    fun main() {
        var low = 20
        val high = 50

        while (low < high) {


            low = low + 1
        }
    }


}