#http://www.pstips.net/passing-arrays-to-pipeline.html

<#
    通过管道传递数组时会把数组展开，这有时候会很奇怪。

    如果一个函数返回了不止一个值，PowerShell会自动将它们包装成一个数组，但是如果你把
它通过管道传递给另一个函数，PowerShell又会自动地把它拆成一个个的元素。如果你想摆脱
PowerShell这多管闲事，不想集合被解析成单个元素，而是作为一个整体传递给管道，可以这样做，
将你的数组放在另外一个数组中。譬如(,$array)
#>