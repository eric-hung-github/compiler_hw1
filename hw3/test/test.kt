class Test {

    fun checkPrimeNumber(num: int): int {
        println(num)

        num = num / 2

        var i = 2


        while (i <= num ) {

            i = i + 1
        }


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