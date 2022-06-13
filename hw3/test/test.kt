class Test {

    fun checkPrimeNumber(num: int): bool {
        var flag = true
        num = num / 2
        for (i 2..num ) {

            if (num % i == 0) {
                flag = false
                return flag
            }
        }
        
        return flag
    }

    fun main() {
        var low = 20
        val high = 50

        while (low < high) {
            var result = checkPrimeNumber(low) 
            if (result)
                println(low)

            low = low + 1
        }
    }


}