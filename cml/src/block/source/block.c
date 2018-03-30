size_t
FUNCTION(cml_block,size)(const TYPE(cml_block) *b)
{
        return b->size;
}

ATOMIC *
FUNCTION(cml_block,data)(const TYPE(cml_block) *b)
{
        return b->data;
}
