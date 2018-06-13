<#
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
1、通过new-object创建新对象：
#>

#$new_object_test1 = new-object string('*', 100)
#$new_object_test1|get-member|out-default

$new_object_test2 = new-object object
$new_object_test2 | add-member -type NoteProperty -Name First -Value "victor"
$new_object_test2|get-member|out-default


<#
2、noteproperty
#>