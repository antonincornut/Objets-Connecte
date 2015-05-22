<table class="table ">
	<thead>
		<tr>
			<td>Température</td>
			<td>Vent</td>
			<td>Lumière</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>
				<?= $this->Html->image('red.png', array('id' => 'indicator-temp', 'width' => '40px')); ?>
			</td>
			<td>
				<?= $this->Html->image('red.png', array('id' => 'indicator-wind', 'width' => '40px')); ?>
			</td>
			<td>
				<?= $this->Html->image('red.png', array('id' => 'indicator-light', 'width' => '40px')); ?>
			</td>
		</tr>
		<tr>
			<td>
				<p id="temp"></p>
			</td>
			<td>
				<p id="wind"></p>
			</td>
			<td>
				<p id="light"></p>
			</td>
		</tr>
	</tbody>
</table>
<?php echo $this->Html->script('readFile', array('inline' => false)); ?>
