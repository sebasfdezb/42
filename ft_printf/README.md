<h2>Ft_Printf</h2>

<p>Una reimplementación parcial de <code>printf</code> en C. Maneja solo las siguientes conversiones:</p>

<table>
    <thead>
        <tr>
            <th>Conversión</th>
            <th>Descripción Corta</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><code>%c</code></td>
            <td>Imprime un solo carácter.</td>
        </tr>
        <tr>
            <td><code>%s</code></td>
            <td>Imprime una cadena de caracteres.</td>
        </tr>
        <tr>
            <td><code>%p</code></td>
            <td>El argumento de puntero <code>void *</code> se imprime en hexadecimal.</td>
        </tr>
        <tr>
            <td><code>%d</code></td>
            <td>Imprime un número decimal (base 10).</td>
        </tr>
        <tr>
            <td><code>%i</code></td>
            <td>Imprime un entero en base 10.</td>
        </tr>
        <tr>
            <td><code>%u</code></td>
            <td>Imprime un número decimal sin signo (base 10).</td>
        </tr>
        <tr>
            <td><code>%x</code></td>
            <td>Imprime un número en hexadecimal (base 16), en minúsculas.</td>
        </tr>
        <tr>
            <td><code>%X</code></td>
            <td>Imprime un número en hexadecimal (base 16), en mayúsculas.</td>
        </tr>
        <tr>
            <td><code>%%</code></td>
            <td>Imprime un signo de porcentaje.</td>
        </tr>
    </tbody>
</table>
