float funAuxiliar (float x);

float
f2(float x)
{
	return 3 * funAuxiliar(x);
}

float
funAuxiliar (float x)
{
	if ( x < 0 )
		x = -x;

	return x;
}
