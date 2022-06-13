class Test {

    fun checkPrimeNumber(num: int): int {
        var flag = true
        num = num / 2
        for (i 2..num ) {


        }

        return 0
    }

    fun main() {
        var low = 20
        val high = 50
        var result:int

        while (low < high) {
            result = checkPrimeNumber(low) 
            if (result==1)
                println(low)

            low = low + 1
        }
    }


}