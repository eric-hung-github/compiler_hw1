class Test {

    fun checkPrimeNumber(num: int): int {


        return 1
    }

    fun main() {
        var low = 20
        val high = 50
        var result:int

        while (low < high) {
            result = checkPrimeNumber(low) 
            println(result)



            low = low + 1
        }
    }


}